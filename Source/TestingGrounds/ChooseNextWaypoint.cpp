// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "Classes/BehaviorTree/BehaviorTreeComponent.h"
#include "Classes/BehaviorTree/BlackboardComponent.h"



EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	auto BlackboardCompoonent = OwnerComp.GetBlackboardComponent();
	int32 Index = BlackboardCompoonent->GetValueAsInt(IndexKey.SelectedKeyName);

	//UE_LOG(LogTemp, Warning, TEXT("C++ ChooseNextWaypoint"));

	return EBTNodeResult::Succeeded;
}

