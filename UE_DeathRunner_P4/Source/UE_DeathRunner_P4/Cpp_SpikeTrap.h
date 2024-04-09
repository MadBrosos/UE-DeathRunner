// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Cpp_SpikeTrap.generated.h"

UCLASS()
class UE_DEATHRUNNER_P4_API ACpp_SpikeTrap : public AActor
{
	GENERATED_BODY()
	
public:	
	ACpp_SpikeTrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	FVector CurrentSpikeLocation;
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* SpikeMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* SpikePlatformMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UBoxComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UArrowComponent* ArrowComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector InitialSpikeLocation = FVector(0.0f, 0.0f, -200.0f);
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float TimeBeforeAppeared = 0.2f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float TimeBeforeReset = 2.0f;

	UFUNCTION(BlueprintCallable)
	void DeactivateSpike();
	UFUNCTION(BlueprintCallable)
	void ActivateSpike();
	
	UFUNCTION()
    void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void Tick(float DeltaTime) override;
};
