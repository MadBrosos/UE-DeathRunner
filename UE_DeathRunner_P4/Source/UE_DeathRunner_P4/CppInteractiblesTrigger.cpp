// Fill out your copyright notice in the Description page of Project Settings.


#include "CppInteractiblesTrigger.h"

#include "CppInteractiblesInterface.h"

// Sets default values
ACppInteractiblesTrigger::ACppInteractiblesTrigger()
{
}

void ACppInteractiblesTrigger::CppTriggerInteract_Implementation()
{
	// call the interact function on the linked actor
	if (LinkedActor)
	{
		ICppInteractiblesInterface* InteractibleActor = Cast<ICppInteractiblesInterface>(LinkedActor);
		if (InteractibleActor)
		{
			InteractibleActor->Interact();
		}
	}
}

// Called when the game starts or when spawned
void ACppInteractiblesTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACppInteractiblesTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

