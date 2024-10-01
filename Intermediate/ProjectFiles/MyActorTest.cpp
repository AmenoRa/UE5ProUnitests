#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "MyActor.h"
#include "Engine/World.h"

// ����������� �����
DEFINE_SIMPLE_AUTOMATION_TEST(FMyActorTransformTest, "UE5ProUnitests.MyActorTransformTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FMyActorTransformTest::RunTest(const FString& Parameters)
{
    // �������� ������ ���� ��� �����
    UWorld* World = FAutomationEditorCommonUtils::CreateNewMap();
    if (!World)
    {
        AddError(TEXT("Failed to create world for testing."));
        return false;
    }

    // ����� ������ ��� �����
    AMyActor* TestActor = World->SpawnActor<AMyActor>(AMyActor::StaticClass());
    if (!TestActor)
    {
        AddError(TEXT("Failed to spawn test actor."));
        return false;
    }

    // ��������� �������� ���������� ������
    FTransform ActorTransform = TestActor->GetActorTransform();

    // ��������� ���������
    FTransform ExpectedTransform;
    ExpectedTransform.SetLocation(FVector::ZeroVector);
    ExpectedTransform.SetRotation(FQuat::Identity);
    ExpectedTransform.SetScale3D(FVector(1.0f, 1.0f, 1.0f));

    // �������� �� ���������� �����������
    if (!ActorTransform.Equals(ExpectedTransform))
    {
        AddError(FString::Printf(TEXT("Actor transform is incorrect. Expected: %s, but got: %s"), *ExpectedTransform.ToString(), *ActorTransform.ToString()));
        return false;
    }

    // ���� ���� �������
    return true;
}
