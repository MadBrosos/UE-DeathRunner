// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathFunction.h"

#include "Blueprint/UserWidget.h"

void UDeathFunction::SetDeathScreen(UUserWidget* arg, APostProcessVolume* arg2)
{
	deathScreen = arg;
	postProcessVolume = arg2;
}

void UDeathFunction::DeathFunction(UCharacterMovementComponent* characterMovementComponent)
{
	if (!characterMovementComponent) return;
	characterMovementComponent->StopMovementImmediately();
	characterMovementComponent->DisableMovement();
	characterMovementComponent->SetComponentTickEnabled(false);
	if (deathScreen)
	{
		deathScreen->AddToViewport(2);
	}
	if (postProcessVolume)
	{
		postProcessVolume->Settings.ColorSaturation.Set(1, 1, 1,0);
	}
}

void UDeathFunction::RespawnFunction(UCharacterMovementComponent* characterMovementComponent, AActor* player, FVector respawnLocation)
{
	if (!characterMovementComponent ||!player)
	{	
		return;
	}
	
	characterMovementComponent->StopMovementImmediately();
	characterMovementComponent->SetComponentTickEnabled(true);
	characterMovementComponent->MovementMode = MOVE_Walking;
	characterMovementComponent->Velocity = FVector(0, 0, 0);
	player->SetActorLocation(respawnLocation);
	if (deathScreen)
	{
		deathScreen->RemoveFromParent();
	}
	if (postProcessVolume)
	{
		postProcessVolume->Settings.ColorSaturation.Set(1, 1, 1,1);
	}
}
