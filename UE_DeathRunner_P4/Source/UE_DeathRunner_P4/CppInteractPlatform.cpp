// Fill out your copyright notice in the Description page of Project Settings.


#include "CppInteractPlatform.h"

#include "FrameTypes.h"
#include "Kismet/BlueprintTypeConversions.h"

// Sets default values
ACppInteractPlatform::ACppInteractPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ACppInteractPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void ACppInteractPlatform::Interact()
{
	ICppInteractiblesInterface::Interact();
	isInteracted = !isInteracted;
}


// Called every frame
void ACppInteractPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (isInteracted && abs(sqrt(pow(GetActorLocation().X - (StartLocation.X + EndLocation.X), 2))) > 0.1f)
	{
		SetActorLocation(FMath::VInterpTo(GetActorLocation(), StartLocation + EndLocation, DeltaTime, Speed));
	}
	else if (!isInteracted && abs(sqrt(pow(GetActorLocation().X - StartLocation.X, 2))) > 0.1f)
	{
		SetActorLocation(FMath::VInterpTo(GetActorLocation(), StartLocation, DeltaTime, Speed));
	}
}

