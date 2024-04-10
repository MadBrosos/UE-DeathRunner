// Fill out your copyright notice in the Description page of Project Settings.


#include "CppInteractiblesTrigger.h"

#include "CppInteractiblesInterface.h"
#include "Cpp_SpikeTrap.h"

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

	if (LinkedActors.Num() > 0)
	{
		for (AActor* Actor : LinkedActors)
		{

			const auto CppSpikeTrap = Cast<ACpp_SpikeTrap>(Actor);
			if (CppSpikeTrap)
			{
				CppSpikeTrap->ActivateSpike();
				continue;
			}
			
			ICppInteractiblesInterface* InteractibleActor = Cast<ICppInteractiblesInterface>(Actor);
			if (InteractibleActor)
			{
				InteractibleActor->Interact();
			}
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

