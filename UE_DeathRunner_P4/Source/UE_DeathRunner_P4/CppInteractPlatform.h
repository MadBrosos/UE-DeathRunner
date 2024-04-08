// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CppInteractiblesInterface.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Actor.h"
#include "CppInteractPlatform.generated.h"

UCLASS()
class UE_DEATHRUNNER_P4_API ACppInteractPlatform : public AActor, public ICppInteractiblesInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppInteractPlatform();

	bool isInteracted;

	virtual void Interact() override;

	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CppInteractPlatform", meta = (MakeEditWidget = true))
	FVector EndLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CppInteractPlatform")
	float Speed;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
