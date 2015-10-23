// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SHEEPHURRDURR_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

	float speed;
	FVector velocity;
	float rotateSpeed;

	AMyPlayerController();

	virtual void SetupInputComponent() override;
	virtual void Tick(float DeltaTime) override;
	
	void MoveX(float axisValue);
	void MoveY(float axisValue);
	void ToggleMesh();
};
