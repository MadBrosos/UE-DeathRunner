// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DeathFunction.generated.h"

/**
 * 
 */
UCLASS()
class UE_DEATHRUNNER_P4_API UDeathFunction : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "DeathFunction")
	static void DeathFunction(UCharacterMovementComponent* characterMovementComponent);
	UFUNCTION(BlueprintCallable, Category = "DeathFunction")
	static void RespawnFunction(UCharacterMovementComponent* characterMovementComponent, AActor* player, FVector respawnLocation);
	
};
