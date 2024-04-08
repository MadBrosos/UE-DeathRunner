// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CppShoot.generated.h"

/**
 * 
 */
UCLASS()
class UE_DEATHRUNNER_P4_API UCppShoot : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "CppShoot")
	static void Shoot(AActor* ActorHit, FVector CameraForwardVector, float Range);
	
};
