// Fill out your copyright notice in the Description page of Project Settings.


#include "CommonLevelModule.h"

// Sets default values
ACommonLevelModule::ACommonLevelModule()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StaticGroundMeshComponentList = TArray<UStaticMeshComponent*>();
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SpikeMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube'"));
	if (SpikeMeshAsset.Succeeded())
	{
		DefaultSpikeMesh = SpikeMeshAsset.Object;
	}
	else
	{
		// Handle failure to find the mesh asset
	}
}

// Called when the game starts or when spawned
void ACommonLevelModule::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACommonLevelModule::AddComponentToList(UStaticMeshComponent* Component)
{
}



void ACommonLevelModule::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	if (DefaultSpikeMesh)
	{
		FVector Offset = FVector::ZeroVector;
		for (int i = 0; i < numberOfFloorMeshes; i++)
		{
			UStaticMeshComponent* MeshComponent = NewObject<UStaticMeshComponent>(this);
			MeshComponent->SetStaticMesh(DefaultSpikeMesh);
			MeshComponent->SetupAttachment(RootComponent);
			MeshComponent->SetRelativeLocation(Offset); 
			StaticGroundMeshComponentList.Add(MeshComponent);
			FBoxSphereBounds Bounds = MeshComponent->CalcBounds(FTransform());
			Offset += FVector(0, 0, Bounds.BoxExtent.Z * 2); 
		}
	}
	else
	{
		// Handle case where mesh asset was not loaded successfully
	}
}


// Called every frame
void ACommonLevelModule::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

