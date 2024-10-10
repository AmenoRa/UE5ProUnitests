// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAutoUnitestTest.h"
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "MyAutoUnitest.h"



// ��������� ����
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyAutoUnitestTest, "GameTests.MyAutoUnitestTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FMyAutoUnitestTest::RunTest(const FString& Parameters)
{
    // ������� ��������� ������ ��������� ������
    AMyAutoUnitest* UnitTestActor = NewObject<AMyAutoUnitest>();

    // ���������, ��� ����� ��� ������� ������
    if (!UnitTestActor)
    {
        AddError(TEXT("Failed to create AMyAutoUnitest instance."));
        return false;
    }

    // ��������� TargetActor
    UnitTestActor->TargetActor = NewObject<AActor>();

    // ������������� ��������� ���������� TargetActor � ����
    UnitTestActor->TargetActor->SetActorLocation(FVector::ZeroVector);

    // �������� ������������� ������
    FTransform TargetTransform = UnitTestActor->GetTargetActorTransform();

    // ���������, ��� ������������� ����� ��������� ����� ���������
    if (TargetTransform.GetLocation() != FVector::ZeroVector)
    {
        AddError(TEXT("Target actor is not at the origin (0, 0, 0)."));
        return false;
    }

    // ���� ���� ��������, ���������� true
    return true;
}