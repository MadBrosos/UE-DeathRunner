// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathFunction.h"

void UDeathFunction::DeathFunction(UCharacterMovementComponent* characterMovementComponent)
{
	if (!characterMovementComponent) return;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You died!"));		
	characterMovementComponent->StopMovementImmediately();
	characterMovementComponent->DisableMovement();
	characterMovementComponent->SetComponentTickEnabled(false);
}

void UDeathFunction::RespawnFunction(UCharacterMovementComponent* characterMovementComponent, AActor* player, FVector respawnLocation)
{
	if (!characterMovementComponent)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No charaMovementComponent found!"));		
		return;
	}
	if(!player)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No player found!"));		
		return;
	}
	
	characterMovementComponent->StopMovementImmediately();
	characterMovementComponent->SetComponentTickEnabled(true);
	characterMovementComponent->MovementMode = MOVE_Walking;
	characterMovementComponent->Velocity = FVector(0, 0, 0);
	player->SetActorLocation(respawnLocation);
}
