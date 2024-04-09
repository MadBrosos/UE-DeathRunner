// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CommonLevelModule.generated.h"

UCLASS()
class UE_DEATHRUNNER_P4_API ACommonLevelModule : public AActor
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:
	ACommonLevelModule();
	TArray<UStaticMeshComponent*> StaticGroundMeshComponentList;
	UPROPERTY( BlueprintReadOnly ,EditAnywhere, Category = "Mesh" )
	int numberOfFloorMeshes = 2;
	UStaticMesh* DefaultSpikeMesh;
	void AddComponentToList(UStaticMeshComponent* Component);
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void Tick(float DeltaTime) override;
};
