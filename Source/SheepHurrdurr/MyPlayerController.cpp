// Fill out your copyright notice in the Description page of Project Settings.

#include "SheepHurrdurr.h"
#include "MyPlayerController.h"
#include "Dog.h"

AMyPlayerController::AMyPlayerController()
{
	speed = 100.0f;
	rotateSpeed = 1.0f;
}

void AMyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveX", this, &AMyPlayerController::MoveX);
	InputComponent->BindAxis("MoveY", this, &AMyPlayerController::MoveY);
	InputComponent->BindAction("ToggleMesh", IE_Pressed, this, &AMyPlayerController::ToggleMesh);
}

void AMyPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	APawn* pawn = GetPawn();
	//Turn
	FRotator newRotation = pawn->GetActorRotation();
	newRotation.Yaw += velocity.Y;
	pawn->SetActorRotation(newRotation);
	//Move forwards or backwards
	pawn->GetMovementComponent()->AddInputVector(pawn ->GetActorForwardVector()*velocity.X*DeltaTime);
}

void AMyPlayerController::MoveX(float axisValue)
{
	velocity.X = axisValue * speed;
}
void AMyPlayerController::MoveY(float axisValue)
{
	velocity.Y = FMath::Clamp(axisValue, -1.0f, 1.0f) * rotateSpeed;
}

void AMyPlayerController::ToggleMesh()
{
	Cast<ADog>(GetPawn())->ToggleMesh();
}