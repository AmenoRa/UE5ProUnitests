// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAutoUnitest.h"

// Sets default values
AMyAutoUnitest::AMyAutoUnitest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyAutoUnitest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyAutoUnitest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FTransform AMyAutoUnitest::GetTargetActorTransform() const
{
    if (TargetActor)
    {
        return TargetActor->GetActorTransform(); // Получение трансформации выбранного актора
    }
    return FTransform(); // Возвращаем пустой трансформ, если TargetActor не назначен
}
