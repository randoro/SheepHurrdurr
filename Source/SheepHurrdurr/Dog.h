// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Dog.generated.h"

UCLASS()
class SHEEPHURRDURR_API ADog : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	USphereComponent* CollisionSphere;

	UPROPERTY(EditAnywhere)
	UFloatingPawnMovement* MovementComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* OtherMesh;

	UPROPERTY(EditAnywhere)
	UCameraComponent* Camera;

public:
	// Sets default values for this pawn's properties
	ADog();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void ToggleMesh();

	virtual UPawnMovementComponent* GetMovementComponent() const override;
	
};
