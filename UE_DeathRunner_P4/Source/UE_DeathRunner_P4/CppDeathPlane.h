// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppDeathPlane.generated.h"

UCLASS()
class UE_DEATHRUNNER_P4_API ACppDeathPlane : public AActor
{
	GENERATED_BODY()
	
public:
	void Respawn();
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	// Sets default values for this actor's properties
	ACppDeathPlane();
	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* BoxComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite , Category = "DeathPlane", meta = (MakeEditWidget = true))
	FVector SpawnLocation;
	AActor* Player;

	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};