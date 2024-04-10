// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppInteractiblesTrigger.generated.h"

UCLASS()
class UE_DEATHRUNNER_P4_API ACppInteractiblesTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppInteractiblesTrigger();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CppInteractiblesTrigger")
	AActor* LinkedActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CppInteractiblesTrigger")
	TArray<AActor*> LinkedActors;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CppInteractiblesTrigger")
	void CppTriggerInteract();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
