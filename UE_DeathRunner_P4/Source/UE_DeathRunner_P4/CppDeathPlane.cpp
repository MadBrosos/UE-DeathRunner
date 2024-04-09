// Fill out your copyright notice in the Description page of Project Settings.


#include "CppDeathPlane.h"

#include "CppPlayerDeath.h"
#include "Components/BoxComponent.h"

void ACppDeathPlane::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OtherActor->SetActorLocation(SpawnLocation);
	UCppPlayerDeath::PlayerDeath(OtherActor);
}

// Sets default values
ACppDeathPlane::ACppDeathPlane()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//set the box component visible in editor but not in game
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetCollisionProfileName(TEXT("Trigger"));
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ACppDeathPlane::OnOverlapBegin);
	RootComponent = BoxComponent;

}

// Called when the game starts or when spawned
void ACppDeathPlane::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACppDeathPlane::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}