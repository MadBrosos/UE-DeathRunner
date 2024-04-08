// Fill out your copyright notice in the Description page of Project Settings.
#include "Cpp_SpikeTrap.h"

ACpp_SpikeTrap::ACpp_SpikeTrap()
{
	PrimaryActorTick.bCanEverTick = true;

	// Create Root
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ROOT"));
	
#pragma region Spike Mesh
	// SpikeMesh
	SpikeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpikeMesh"));
	SpikeMesh->SetupAttachment(RootComponent);
	InitialSpikeLocation = SpikeMesh->GetComponentLocation();

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

	// Box Collision Settings
	CollisionBox->InitBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ACpp_SpikeTrap::OnBeginOverlap);
}

// Called when the game starts or when spawned
void ACpp_SpikeTrap::BeginPlay()
{
	Super::BeginPlay();
	SpikeMesh->SetVisibility(false);
}


void ACpp_SpikeTrap::DeactivateSpike()
{
	UE_LOG(LogTemp, Warning, TEXT("DeactivateSpike called"));
	SpikeMesh->SetRelativeLocation(InitialSpikeLocation);
	UE_LOG(LogTemp, Warning, TEXT("SpikeMesh Location: %s"), *SpikeMesh->GetComponentLocation().ToString());
	SpikeMesh->SetVisibility(false);
}

void ACpp_SpikeTrap::ActivateSpike()
{
	SpikeMesh->SetVisibility(true);

	FVector TargetLocation = InitialSpikeLocation;
	TargetLocation.Z += 200.0f;

	CurrentSpikeLocation = SpikeMesh->GetRelativeLocation();

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


void ACpp_SpikeTrap::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap"));
}

// Called every frame
void ACpp_SpikeTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

