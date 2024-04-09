// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Cpp_SpikeTrap.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Cpp_SpikeDetect.generated.h"

UCLASS()
class UE_DEATHRUNNER_P4_API ACpp_SpikeDetect : public AActor
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* SpikeMeshDetect;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBoxComponent* CollisionBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> SpikeTraps;
	AActor* SpikeTrap;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	ACpp_SpikeDetect();
	virtual void Tick(float DeltaTime) override;

};
