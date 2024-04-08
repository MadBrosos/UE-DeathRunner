// Fill out your copyright notice in the Description page of Project Settings.


#include "Cpp_SpikeDetect.h"


// Sets default values
ACpp_SpikeDetect::ACpp_SpikeDetect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Create Root
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("ROOT"));

	SpikeTrap = nullptr;	
#pragma region Spike Mesh
	// SpikeMesh
	SpikeMeshDetect = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SpikeMesh"));
	SpikeMeshDetect->SetupAttachment(RootComponent);

	// Set Spike Mesh
	//static ConstructorHelpers::FObjectFinder<UStaticMesh> SpikeMeshAsset(TEXT("StaticMesh'/Engine/Plugins/ControlRigContent/Controls/ControlRig_Box_solid'"));
	/*
	 
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SpikeMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube'"));
	if (SpikeMeshAsset.Succeeded())
	{
		SpikeMeshDetect->SetStaticMesh(SpikeMeshAsset.Object);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Le mesh ControlRig_Box_solid n'a pas été trouvé."));
	}
	*/
#pragma  endregion

#pragma region Box Collision
	// Create Box Collision
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpikeCollision"));
	CollisionBox->SetupAttachment(SpikeMeshDetect); 
	CollisionBox->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

	// Box Collision Settings
	CollisionBox->InitBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ACpp_SpikeDetect::OnBeginOverlap);
#pragma  endregion
}

// Called when the game starts or when spawned
void ACpp_SpikeDetect::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACpp_SpikeDetect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACpp_SpikeDetect::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const auto CppSpikeTrap = Cast<ACpp_SpikeTrap>(SpikeTrap);
	CppSpikeTrap->ActivateSpike();
	UE_LOG(LogTemp, Warning, TEXT("SpikeTrap Activated"));
}


