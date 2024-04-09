// Fill out your copyright notice in the Description page of Project Settings.
#include "Cpp_SpikeTrap.h"

#include "DeathFunction.h"

ACpp_SpikeTrap::ACpp_SpikeTrap()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create Root
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ROOT"));
	
#pragma region Spike Mesh
	// SpikeMesh
	SpikeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpikeMesh"));
	SpikeMesh->SetupAttachment(RootComponent);
	InitialSpikeLocation = GetActorLocation();

	// Set Spike Mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SpikeMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube'"));
	if (SpikeMeshAsset.Succeeded())
	{
		SpikeMesh->SetStaticMesh(SpikeMeshAsset.Object);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Le mesh ControlRig_Box_solid n'a pas été trouvé."));
	}
#pragma  endregion

#pragma region SpikePlatform Mesh
	// SpikePlatformMesh
	SpikePlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpikePlatformMesh"));
	SpikePlatformMesh->SetupAttachment(RootComponent);
	SpikePlatformMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> SpikeMeshPlatformAsset(TEXT("StaticMesh'/Engine/Plugins/ControlRigContent/Controls/ControlRig_Box_solid'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SpikeMeshPlatformAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube'"));
	if (SpikeMeshPlatformAsset.Succeeded())
	{
		SpikePlatformMesh->SetStaticMesh(SpikeMeshPlatformAsset.Object);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Le mesh ControlRig_Box_solid n'a pas été trouvé."));
	}
#pragma endregion

#pragma region Arrow Component
	// Arrow Component
	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	ArrowComponent->SetupAttachment(RootComponent);
	ArrowComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	ArrowComponent->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
#pragma endregion
	
	// Create Box Collision
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpikeCollision"));
	CollisionBox->SetupAttachment(SpikeMesh); 
	CollisionBox->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	CollisionBox->SetCollisionProfileName(TEXT("Trigger"));

	// Box Collision Settings
	CollisionBox->InitBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ACpp_SpikeTrap::OnBeginOverlap);
	
}

// Called when the game starts or when spawned
void ACpp_SpikeTrap::BeginPlay()
{
	Super::BeginPlay();
	CollisionBox->SetRelativeLocation(FVector(0.0f, 0.0f, -1000.0f));
	SpikeMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -1000.0f));
}


void ACpp_SpikeTrap::DeactivateSpike()
{
	UE_LOG(LogTemp, Warning, TEXT("DeactivateSpike called"));
	SpikeMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -1000.0f));
	CollisionBox->SetRelativeLocation(FVector(0.0f, 0.0f, -1000.0f));
	UE_LOG(LogTemp, Warning, TEXT("SpikeMesh Location: %s"), *SpikeMesh->GetComponentLocation().ToString());

	FString SpikeMeshLocation = SpikeMesh->GetComponentLocation().ToString();
}

void ACpp_SpikeTrap::ActivateSpike()
{

	FVector TargetLocation = InitialSpikeLocation;
	TargetLocation.Z += 200.0f;

	CurrentSpikeLocation = SpikeMesh->GetRelativeLocation();
	SpikeMesh->SetRelativeLocation(InitialSpikeLocation);
	CollisionBox->SetRelativeLocation(InitialSpikeLocation);

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this, TargetLocation, &TimerHandle]()
	{
		FVector NewLocation = FMath::VInterpTo(CurrentSpikeLocation, TargetLocation, GetWorld()->GetDeltaSeconds(), 0.2f);
		SpikeMesh->SetRelativeLocation(NewLocation);

		FTimerDelegate DeactivateDelegate = FTimerDelegate::CreateLambda([this]()
		{
			DeactivateSpike();
		});
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, DeactivateDelegate, TimeBeforeReset, false);
	}, TimeBeforeAppeared, false);
}

void ACpp_SpikeTrap::Respawn()
{
	UDeathFunction::RespawnFunction(Player->FindComponentByClass<UCharacterMovementComponent>(), Player, FVector(0,0,150));
}


void ACpp_SpikeTrap::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Player == OtherActor)
	{
		return;
	}
	Player = OtherActor;
	UDeathFunction::DeathFunction(Player->FindComponentByClass<UCharacterMovementComponent>());
	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, this, &ACpp_SpikeTrap::Respawn, 5.0f, false);
}

// Called every frame
void ACpp_SpikeTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

