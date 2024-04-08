// Fill out your copyright notice in the Description page of Project Settings.


#include "CppInteractibleWall.h"

// Sets default values
ACppInteractibleWall::ACppInteractibleWall()
{	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ACppInteractibleWall::Interact()
{
	ICppInteractiblesInterface::Interact();

	SetActorRelativeLocation(FVector(0, 0, -1000));
}


// Called when the game starts or when spawned
void ACppInteractibleWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACppInteractibleWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

