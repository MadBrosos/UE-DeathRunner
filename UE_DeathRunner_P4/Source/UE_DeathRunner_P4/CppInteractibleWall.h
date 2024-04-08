// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CppInteractiblesInterface.h"
#include "GameFramework/Actor.h"
#include "CppInteractibleWall.generated.h"

UCLASS()
class UE_DEATHRUNNER_P4_API ACppInteractibleWall : public AActor, public ICppInteractiblesInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppInteractibleWall();

	//implementing the interface
	virtual void Interact() override;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
