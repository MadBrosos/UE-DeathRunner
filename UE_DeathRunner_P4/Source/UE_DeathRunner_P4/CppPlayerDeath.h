// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CppPlayerDeath.generated.h"

/**
 * 
 */
UCLASS()
class UE_DEATHRUNNER_P4_API UCppPlayerDeath : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Death")
	static void PlayerDeath(AActor* TargetActor);
	
};
