// Fill out your copyright notice in the Description page of Project Settings.

#include "SheepHurrdurr.h"
#include "Dog.h"


// Sets default values
ADog::ADog()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	CollisionSphere =
		CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	CollisionSphere->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	//Might want to tweak this in the editor depending on the size of the static mesh
	CollisionSphere->InitSphereRadius(10.0f);
	CollisionSphere->SetCollisionProfileName(TEXT("Pawn"));
	RootComponent = CollisionSphere;

	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("MovementComponent");
	MovementComponent->SetUpdatedComponent(RootComponent);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->AttachTo(RootComponent);

	OtherMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OtherMesh"));
	OtherMesh->AttachTo(RootComponent);
	OtherMesh->SetVisibility(false);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->AttachTo(RootComponent);
	Camera->SetRelativeLocation(FVector(-100.0f, 0.0f, 200.0f));
	Camera->SetRelativeRotation(FRotator(-60.0f, 0.0f, 0.0f));

}

// Called when the game starts or when spawned
void ADog::BeginPlay()
{
	Super::BeginPlay();
	//test comment
	
}

// Called every frame
void ADog::Tick( float DeltaTime )
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADog::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ADog::ToggleMesh()
{
	StaticMesh->ToggleVisibility();
	OtherMesh->ToggleVisibility();
}

UPawnMovementComponent* ADog::GetMovementComponent() const
{
	return MovementComponent;
}