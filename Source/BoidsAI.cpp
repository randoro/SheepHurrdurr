// Fill out your copyright notice in the Description page of Project Settings.

#include "SheepHurrdurr.h"
#include "BoidsAI.h"


// Sets default values
ABoidsAI::ABoidsAI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABoidsAI::BeginPlay()
{
	FVector temp = FVector(FMath::Rand(), FMath::Rand(), 0);
	temp.Normalize();
	temp *= 100;
	GetMovementComponent()->Velocity = temp;
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, GetMovementComponent()->Velocity.ToString());

	
}

// Called every frame
void ABoidsAI::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	FVector direction;
	Alignment();
	Cohesion();
	Separation();
	direction = alignmenVec + cohesionVec + separationVec;
	direction *= 100;
	direction.Normalize();
	GetMovementComponent()->AddInputVector(direction);

	//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, alignmenVec.ToString() + cohesionVec.ToString()+separationVec.ToString());


}

// Called to bind functionality to input
void ABoidsAI::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}


void ABoidsAI::Alignment()
{
	for (TActorIterator<ABoidsAI> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (*ActorItr != this)
		{
			if (GetDistanceTo(*ActorItr) < 300)
			{
				alignmenVec += ActorItr->GetVelocity();
			}
		}
	}
	alignmenVec.Normalize();
}

void ABoidsAI::Cohesion()
{
	int numActor(0);
	for (TActorIterator<ABoidsAI> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (*ActorItr != this)
		{
			if (GetDistanceTo(*ActorItr) < 300)
			{
				cohesionVec += ActorItr->GetActorLocation();
				numActor++;
			}
		}
	}
	cohesionVec /= numActor;
	cohesionVec -= GetActorLocation();
	cohesionVec.Normalize();
}


void ABoidsAI::Separation()
{
	int numActor(0);
	for (TActorIterator<ABoidsAI> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (*ActorItr != this)
		{
			if (GetDistanceTo(*ActorItr) < 300)
			{
				separationVec += ActorItr->GetActorLocation() - GetActorLocation();
				numActor++;
			}
		}
	}
	separationVec /= numActor;
	separationVec *= -1;
	separationVec.Normalize();
}



