// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "Classes/BehaviorTree/BehaviorTreeComponent.h"
#include "Classes/BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolPointsComponent.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Get Patrol Points
	AAIController* AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrolPointsComp = ControlledPawn->FindComponentByClass<UPatrolPointsComponent>();

	if (!ensure(PatrolPointsComp))
	{
		return EBTNodeResult::Failed;
	}

	//Warn about empty patrol routes
	auto PatrolPoints = PatrolPointsComp->GetPatrolPoints();

	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("A guard is missing patrol points"));
		return EBTNodeResult::Failed;
	}

	//Set net waypoint
	auto BlackBoardComponent = OwnerComp.GetBlackboardComponent();
	auto Index = BlackBoardComponent->GetValueAsInt(IndexKey.SelectedKeyName);

	BlackBoardComponent->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	//Cycle the index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackBoardComponent->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	UE_LOG(LogTemp, Warning, TEXT("Waypoint index: %i"), Index);

	return EBTNodeResult::Succeeded;
}

