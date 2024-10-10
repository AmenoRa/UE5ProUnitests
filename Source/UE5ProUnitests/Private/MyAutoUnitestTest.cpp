// Fill out your copyright notice in the Description page of Project Settings.

#include "MyAutoUnitestTest.h"
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "MyAutoUnitest.h"



// Объявляем тест
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMyAutoUnitestTest, "GameTests.MyAutoUnitestTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FMyAutoUnitestTest::RunTest(const FString& Parameters)
{
    // Создаем экземпляр нашего тестового актора
    AMyAutoUnitest* UnitTestActor = NewObject<AMyAutoUnitest>();

    // Проверяем, что актор был успешно создан
    if (!UnitTestActor)
    {
        AddError(TEXT("Failed to create AMyAutoUnitest instance."));
        return false;
    }

    // Назначаем TargetActor
    UnitTestActor->TargetActor = NewObject<AActor>();

    // Устанавливаем начальные координаты TargetActor в ноль
    UnitTestActor->TargetActor->SetActorLocation(FVector::ZeroVector);

    // Получаем трансформацию актора
    FTransform TargetTransform = UnitTestActor->GetTargetActorTransform();

    // Проверяем, что трансформация равна начальной точке координат
    if (TargetTransform.GetLocation() != FVector::ZeroVector)
    {
        AddError(TEXT("Target actor is not at the origin (0, 0, 0)."));
        return false;
    }

    // Если тест проходит, возвращаем true
    return true;
}