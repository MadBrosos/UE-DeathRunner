// Fill out your copyright notice in the Description page of Project Settings.


#include "CppShoot.h"

#include "CppInteractiblesTrigger.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCppShoot::Shoot(AActor* ActorHit, FVector CameraForwardVector, float Range)
{
	if (!ActorHit)
	{
		return;
	}
	ACppInteractiblesTrigger* Interactible = Cast<ACppInteractiblesTrigger>(ActorHit);
	UCharacterMovementComponent* MovementComponent = Cast<UCharacterMovementComponent>(ActorHit->GetComponentByClass(UCharacterMovementComponent::StaticClass()));
	if (Interactible)
	{
		Interactible->CppTriggerInteract();
	}
	else if (MovementComponent)
	{
		FVector2f XY = FVector2f(CameraForwardVector.X, CameraForwardVector.Y) * Range;
		float Z = CameraForwardVector.Z * Range + 500;
		FVector Direction = FVector(XY.X, XY.Y, Z);
		MovementComponent->Launch(Direction);
	}
}
