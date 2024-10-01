#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "MyActor.h"
#include "Engine/World.h"

// Регистрация теста
DEFINE_SIMPLE_AUTOMATION_TEST(FMyActorTransformTest, "UE5ProUnitests.MyActorTransformTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FMyActorTransformTest::RunTest(const FString& Parameters)
{
    // Создание нового мира для теста
    UWorld* World = FAutomationEditorCommonUtils::CreateNewMap();
    if (!World)
    {
        AddError(TEXT("Failed to create world for testing."));
        return false;
    }

    // Спавн актора для теста
    AMyActor* TestActor = World->SpawnActor<AMyActor>(AMyActor::StaticClass());
    if (!TestActor)
    {
        AddError(TEXT("Failed to spawn test actor."));
        return false;
    }

    // Получение текущего трансформа актора
    FTransform ActorTransform = TestActor->GetActorTransform();

    // Ожидаемый трансформ
    FTransform ExpectedTransform;
    ExpectedTransform.SetLocation(FVector::ZeroVector);
    ExpectedTransform.SetRotation(FQuat::Identity);
    ExpectedTransform.SetScale3D(FVector(1.0f, 1.0f, 1.0f));

    // Проверка на совпадение трансформов
    if (!ActorTransform.Equals(ExpectedTransform))
    {
        AddError(FString::Printf(TEXT("Actor transform is incorrect. Expected: %s, but got: %s"), *ExpectedTransform.ToString(), *ActorTransform.ToString()));
        return false;
    }

    // Если тест успешен
    return true;
}
