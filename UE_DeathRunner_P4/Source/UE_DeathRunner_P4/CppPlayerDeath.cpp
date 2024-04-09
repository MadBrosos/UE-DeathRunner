// Fill out your copyright notice in the Description page of Project Settings.


#include "CppPlayerDeath.h"

void UCppPlayerDeath::PlayerDeath(AActor* TargetActor)
{
	TArray<USkeletalMeshComponent*> SkeletalMeshComponents;
	TargetActor->GetComponents<USkeletalMeshComponent>(SkeletalMeshComponents);
	for (USkeletalMeshComponent* SkeletalMeshComponent : SkeletalMeshComponents)
	{
		SkeletalMeshComponent->SetAllBodiesSimulatePhysics(true);
		SkeletalMeshComponent->SetSimulatePhysics(true);
	}
}
