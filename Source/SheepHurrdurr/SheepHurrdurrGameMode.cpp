// Fill out your copyright notice in the Description page of Project Settings.

#include "SheepHurrdurr.h"
#include "SheepHurrdurrGameMode.h"
#include "MyPlayerController.h"


ASheepHurrdurrGameMode::ASheepHurrdurrGameMode() 
{
	this->PlayerControllerClass = AMyPlayerController::StaticClass();
}

