////////////////////////////////////////////////////////////////////////////////
//
// MIT License
// 
// Copyright (c) 2018-2019 Nuraga Wiswakarma
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
////////////////////////////////////////////////////////////////////////////////
// 

#pragma once

#include "CoreMinimal.h"
#include "JCVDiagram.h"
#include "JCVParameters.h"

class FJCVDiagramMap;
struct FJCVCell;

typedef TFunction<bool(FJCVCell&,FJCVCell&,FJCVEdge&)> FJCVNeighbourVisitCallback;

class FJCVCellUtility
{
public:

    static void PointFillVisit(
        FJCVDiagramMap& Map,
        const TArray<FJCVCell*>& OriginCells,
        const FJCVNeighbourVisitCallback& VisitCallback
        );

    static void ExpandVisit(
        FJCVDiagramMap& Map,
        int32 ExpandCount,
        const TArray<FJCVCell*>& OriginCells,
        const FJCVNeighbourVisitCallback& VisitCallback
        );

    static float GetClosestDistanceFromCellSq(
        FJCVDiagramMap& Map,
        const FJCVCell& OriginCell,
        const FJCVFeatureId& FeatureId,
        bool bAgainstAnyType = false
        );

    static float GetFurthestDistanceFromCellSq(
        FJCVDiagramMap& Map,
        const FJCVCell& OriginCell,
        const FJCVFeatureId& FeatureId,
        bool bAgainstAnyType = false
        );

    FORCEINLINE static float GetClosestDistanceFromCell(
        FJCVDiagramMap& Map,
        const FJCVCell& OriginCell,
        const FJCVFeatureId& FeatureId,
        bool bAgainstAnyType = false
        )
    {
        return FMath::Sqrt(GetClosestDistanceFromCellSq(Map, OriginCell, FeatureId, bAgainstAnyType));
    }

    FORCEINLINE static float GetFurthestDistanceFromCell(
        FJCVDiagramMap& Map,
        const FJCVCell& OriginCell,
        const FJCVFeatureId& FeatureId,
        bool bAgainstAnyType = false
        )
    {
        return FMath::Sqrt(GetFurthestDistanceFromCellSq(Map, OriginCell, FeatureId, bAgainstAnyType));
    }
};
