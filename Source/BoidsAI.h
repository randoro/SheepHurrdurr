// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BoidsAI.generated.h"

UCLASS()
class SHEEPHURRDURR_API ABoidsAI : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABoidsAI();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

private:
	FVector alignmenVec;
	FVector cohesionVec;
	FVector separationVec;
	void Alignment();
	void Cohesion();
	void Separation();
	
};
