test.c:7:6: warning: variable length array folded to constant array as an extension [-Wgnu-folding-constant]
 int mult1[len] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
     ^
test.c:8:6: warning: variable length array folded to constant array as an extension [-Wgnu-folding-constant]
 int mult2[len] = {2, 3, 4, 2, 5, 7 ,9 ,9, 0, 1, 9, 8, 7, 6, 4, 3, 2, 1, 2, 2};
     ^
test.c:13:6: warning: variable length array folded to constant array as an extension [-Wgnu-folding-constant]
 int result[len * 2] = {};
     ^
; ModuleID = '-'
source_filename = "-"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@len = dso_local constant i32 20, align 4
@__const.main.mult1 = private unnamed_addr constant [20 x i32] [i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 0], align 16
@__const.main.mult2 = private unnamed_addr constant [20 x i32] [i32 2, i32 3, i32 4, i32 2, i32 5, i32 7, i32 9, i32 9, i32 0, i32 1, i32 9, i32 8, i32 7, i32 6, i32 4, i32 3, i32 2, i32 1, i32 2, i32 2], align 16

; Function Attrs: noinline nounwind optnone
define dso_local i32 @main() #0 {
entry:
  %retval = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %t = alloca i32, align 4
  %n = alloca i32, align 4
  %temp = alloca i32, align 4
  %mult1 = alloca [20 x i32], align 16
  %mult2 = alloca [20 x i32], align 16
  %len1 = alloca i32, align 4
  %len2 = alloca i32, align 4
  %saved_stack = alloca i8*, align 8
  %result = alloca [40 x i32], align 16
  store i32 0, i32* %retval, align 4
  %0 = bitcast [20 x i32]* %mult1 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %0, i8* align 16 bitcast ([20 x i32]* @__const.main.mult1 to i8*), i64 80, i1 false)
  %1 = bitcast [20 x i32]* %mult2 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 16 %1, i8* align 16 bitcast ([20 x i32]* @__const.main.mult2 to i8*), i64 80, i1 false)
  store i32 20, i32* %len1, align 4
  store i32 20, i32* %len2, align 4
  %2 = call i8* @llvm.stacksave()
  store i8* %2, i8** %saved_stack, align 8
  %vla = alloca i32, i64 25, align 16
  %vla1 = alloca i32, i64 25, align 16
  %3 = bitcast [40 x i32]* %result to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %3, i8 0, i64 160, i1 false)
  store i32 0, i32* %i, align 4
  br label %while.cond

while.cond:                                       ; preds = %while.body, %entry
  %4 = load i32, i32* %i, align 4
  %5 = load i32, i32* %len1, align 4
  %cmp = icmp slt i32 %4, %5
  br i1 %cmp, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %6 = load i32, i32* %i, align 4
  %idxprom = sext i32 %6 to i64
  %arrayidx = getelementptr inbounds [20 x i32], [20 x i32]* %mult1, i64 0, i64 %idxprom
  %7 = load i32, i32* %arrayidx, align 4
  %8 = load i32, i32* %i, align 4
  %idxprom2 = sext i32 %8 to i64
  %arrayidx3 = getelementptr inbounds i32, i32* %vla, i64 %idxprom2
  store i32 %7, i32* %arrayidx3, align 4
  %9 = load i32, i32* %i, align 4
  %add = add nsw i32 %9, 1
  store i32 %add, i32* %i, align 4
  br label %while.cond, !llvm.loop !2

while.end:                                        ; preds = %while.cond
  store i32 0, i32* %i, align 4
  br label %while.cond4

while.cond4:                                      ; preds = %while.body6, %while.end
  %10 = load i32, i32* %i, align 4
  %11 = load i32, i32* %len2, align 4
  %cmp5 = icmp slt i32 %10, %11
  br i1 %cmp5, label %while.body6, label %while.end12

while.body6:                                      ; preds = %while.cond4
  %12 = load i32, i32* %i, align 4
  %idxprom7 = sext i32 %12 to i64
  %arrayidx8 = getelementptr inbounds [20 x i32], [20 x i32]* %mult2, i64 0, i64 %idxprom7
  %13 = load i32, i32* %arrayidx8, align 4
  %14 = load i32, i32* %i, align 4
  %idxprom9 = sext i32 %14 to i64
  %arrayidx10 = getelementptr inbounds i32, i32* %vla1, i64 %idxprom9
  store i32 %13, i32* %arrayidx10, align 4
  %15 = load i32, i32* %i, align 4
  %add11 = add nsw i32 %15, 1
  store i32 %add11, i32* %i, align 4
  br label %while.cond4, !llvm.loop !4

while.end12:                                      ; preds = %while.cond4
  %16 = load i32, i32* %len1, align 4
  %17 = load i32, i32* %len2, align 4
  %add13 = add nsw i32 %16, %17
  %sub = sub nsw i32 %add13, 1
  store i32 %sub, i32* %n, align 4
  store i32 0, i32* %i, align 4
  br label %while.cond14

while.cond14:                                     ; preds = %while.body16, %while.end12
  %18 = load i32, i32* %i, align 4
  %19 = load i32, i32* %n, align 4
  %cmp15 = icmp sle i32 %18, %19
  br i1 %cmp15, label %while.body16, label %while.end20

while.body16:                                     ; preds = %while.cond14
  %20 = load i32, i32* %i, align 4
  %idxprom17 = sext i32 %20 to i64
  %arrayidx18 = getelementptr inbounds [40 x i32], [40 x i32]* %result, i64 0, i64 %idxprom17
  store i32 0, i32* %arrayidx18, align 4
  %21 = load i32, i32* %i, align 4
  %add19 = add nsw i32 %21, 1
  store i32 %add19, i32* %i, align 4
  br label %while.cond14, !llvm.loop !5

while.end20:                                      ; preds = %while.cond14
  store i32 0, i32* %temp, align 4
  %22 = load i32, i32* %len2, align 4
  %sub21 = sub nsw i32 %22, 1
  store i32 %sub21, i32* %i, align 4
  br label %while.cond22

while.cond22:                                     ; preds = %while.end50, %while.end20
  %23 = load i32, i32* %i, align 4
  %cmp23 = icmp sgt i32 %23, -1
  br i1 %cmp23, label %while.body24, label %while.end54

while.body24:                                     ; preds = %while.cond22
  %24 = load i32, i32* %i, align 4
  %idxprom25 = sext i32 %24 to i64
  %arrayidx26 = getelementptr inbounds i32, i32* %vla1, i64 %idxprom25
  %25 = load i32, i32* %arrayidx26, align 4
  store i32 %25, i32* %t, align 4
  %26 = load i32, i32* %len1, align 4
  %sub27 = sub nsw i32 %26, 1
  store i32 %sub27, i32* %j, align 4
  br label %while.cond28

while.cond28:                                     ; preds = %if.end, %while.body24
  %27 = load i32, i32* %j, align 4
  %cmp29 = icmp sgt i32 %27, -1
  br i1 %cmp29, label %while.body30, label %while.end50

while.body30:                                     ; preds = %while.cond28
  %28 = load i32, i32* %n, align 4
  %idxprom31 = sext i32 %28 to i64
  %arrayidx32 = getelementptr inbounds [40 x i32], [40 x i32]* %result, i64 0, i64 %idxprom31
  %29 = load i32, i32* %arrayidx32, align 4
  %30 = load i32, i32* %t, align 4
  %31 = load i32, i32* %j, align 4
  %idxprom33 = sext i32 %31 to i64
  %arrayidx34 = getelementptr inbounds i32, i32* %vla, i64 %idxprom33
  %32 = load i32, i32* %arrayidx34, align 4
  %mul = mul nsw i32 %30, %32
  %add35 = add nsw i32 %29, %mul
  store i32 %add35, i32* %temp, align 4
  %33 = load i32, i32* %temp, align 4
  %cmp36 = icmp sge i32 %33, 10
  br i1 %cmp36, label %if.then, label %if.else

if.then:                                          ; preds = %while.body30
  %34 = load i32, i32* %temp, align 4
  %35 = load i32, i32* %n, align 4
  %idxprom37 = sext i32 %35 to i64
  %arrayidx38 = getelementptr inbounds [40 x i32], [40 x i32]* %result, i64 0, i64 %idxprom37
  store i32 %34, i32* %arrayidx38, align 4
  %36 = load i32, i32* %n, align 4
  %sub39 = sub nsw i32 %36, 1
  %idxprom40 = sext i32 %sub39 to i64
  %arrayidx41 = getelementptr inbounds [40 x i32], [40 x i32]* %result, i64 0, i64 %idxprom40
  %37 = load i32, i32* %arrayidx41, align 4
  %38 = load i32, i32* %temp, align 4
  %div = sdiv i32 %38, 10
  %add42 = add nsw i32 %37, %div
  %39 = load i32, i32* %n, align 4
  %sub43 = sub nsw i32 %39, 1
  %idxprom44 = sext i32 %sub43 to i64
  %arrayidx45 = getelementptr inbounds [40 x i32], [40 x i32]* %result, i64 0, i64 %idxprom44
  store i32 %add42, i32* %arrayidx45, align 4
  br label %if.end

if.else:                                          ; preds = %while.body30
  %40 = load i32, i32* %temp, align 4
  %41 = load i32, i32* %n, align 4
  %idxprom46 = sext i32 %41 to i64
  %arrayidx47 = getelementptr inbounds [40 x i32], [40 x i32]* %result, i64 0, i64 %idxprom46
  store i32 %40, i32* %arrayidx47, align 4
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then
  %42 = load i32, i32* %j, align 4
  %sub48 = sub nsw i32 %42, 1
  store i32 %sub48, i32* %j, align 4
  %43 = load i32, i32* %n, align 4
  %sub49 = sub nsw i32 %43, 1
  store i32 %sub49, i32* %n, align 4
  br label %while.cond28, !llvm.loop !6

while.end50:                                      ; preds = %while.cond28
  %44 = load i32, i32* %n, align 4
  %45 = load i32, i32* %len1, align 4
  %add51 = add nsw i32 %44, %45
  %sub52 = sub nsw i32 %add51, 1
  store i32 %sub52, i32* %n, align 4
  %46 = load i32, i32* %i, align 4
  %sub53 = sub nsw i32 %46, 1
  store i32 %sub53, i32* %i, align 4
  br label %while.cond22, !llvm.loop !7

while.end54:                                      ; preds = %while.cond22
  %arrayidx55 = getelementptr inbounds [40 x i32], [40 x i32]* %result, i64 0, i64 0
  %47 = load i32, i32* %arrayidx55, align 16
  %cmp56 = icmp ne i32 %47, 0
  br i1 %cmp56, label %if.then57, label %if.end59

if.then57:                                        ; preds = %while.end54
  %arrayidx58 = getelementptr inbounds [40 x i32], [40 x i32]* %result, i64 0, i64 0
  %48 = load i32, i32* %arrayidx58, align 16
  call void @_sysy_putint(i32 %48)
  br label %if.end59

if.end59:                                         ; preds = %if.then57, %while.end54
  store i32 1, i32* %i, align 4
  br label %while.cond60

while.cond60:                                     ; preds = %while.body64, %if.end59
  %49 = load i32, i32* %i, align 4
  %50 = load i32, i32* %len1, align 4
  %51 = load i32, i32* %len2, align 4
  %add61 = add nsw i32 %50, %51
  %sub62 = sub nsw i32 %add61, 1
  %cmp63 = icmp sle i32 %49, %sub62
  br i1 %cmp63, label %while.body64, label %while.end68

while.body64:                                     ; preds = %while.cond60
  %52 = load i32, i32* %i, align 4
  %idxprom65 = sext i32 %52 to i64
  %arrayidx66 = getelementptr inbounds [40 x i32], [40 x i32]* %result, i64 0, i64 %idxprom65
  %53 = load i32, i32* %arrayidx66, align 4
  call void @_sysy_putint(i32 %53)
  %54 = load i32, i32* %i, align 4
  %add67 = add nsw i32 %54, 1
  store i32 %add67, i32* %i, align 4
  br label %while.cond60, !llvm.loop !8

while.end68:                                      ; preds = %while.cond60
  store i32 0, i32* %retval, align 4
  %55 = load i8*, i8** %saved_stack, align 8
  call void @llvm.stackrestore(i8* %55)
  %56 = load i32, i32* %retval, align 4
  ret i32 %56
}

; Function Attrs: argmemonly nofree nosync nounwind willreturn
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* noalias nocapture writeonly, i8* noalias nocapture readonly, i64, i1 immarg) #1

; Function Attrs: nofree nosync nounwind willreturn
declare i8* @llvm.stacksave() #2

; Function Attrs: argmemonly nofree nosync nounwind willreturn writeonly
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #3

declare void @_sysy_putint(i32) #4

; Function Attrs: nofree nosync nounwind willreturn
declare void @llvm.stackrestore(i8*) #2

attributes #0 = { noinline nounwind optnone "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-features"="+cx8,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { argmemonly nofree nosync nounwind willreturn }
attributes #2 = { nofree nosync nounwind willreturn }
attributes #3 = { argmemonly nofree nosync nounwind willreturn writeonly }
attributes #4 = { "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-features"="+cx8,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 12.0.1"}
!2 = distinct !{!2, !3}
!3 = !{!"llvm.loop.mustprogress"}
!4 = distinct !{!4, !3}
!5 = distinct !{!5, !3}
!6 = distinct !{!6, !3}
!7 = distinct !{!7, !3}
!8 = distinct !{!8, !3}
3 warnings generated.
