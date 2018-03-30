// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGuardCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API APatrollingGuardCharacter : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*> PatrolPointsFromCPP;
};
