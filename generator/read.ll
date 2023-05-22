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
-------------------------------------------------------------------------------------------------------
; ModuleID = '-'
source_filename = "-"

@len = constant i32 20

declare void @_sysy_starttime(i32)

declare void @_sysy_stoptime(i32)

declare i32 @_sysy_getch()

declare void @_sysy_putch(i32)

declare i32 @_sysy_getint()

declare void @_sysy_putint(i32)

declare i32 @_sysy_getarray(i32*)

declare void @_sysy_putarray(i32, i32*)

define i32 @main() {
entry:
  %result = alloca [40 x i32], align 1
  %c2 = alloca [65903345 x i32], align 1
  %c1 = alloca [65903345 x i32], align 1
  %len2 = alloca i32, align 1
  %len1 = alloca i32, align 1
  %mult2 = alloca [20 x i32], align 1
  %mult1 = alloca [20 x i32], align 1
  %i = alloca i32, align 1
  %j = alloca i32, align 1
  %t = alloca i32, align 1
  %n = alloca i32, align 1
  %temp = alloca i32, align 1
  %retval = alloca i32, align 1
  store i32 0, i32* %retval, align 1
  %0 = bitcast [20 x i32]* %mult1 to i8*
  call void @llvm.memset.p0i8.i32(i8* align 4 %0, i8 0, i32 80, i1 false)
  %mult11 = getelementptr inbounds [20 x i32], [20 x i32]* %mult1, i32 0
  %mult12 = getelementptr inbounds [20 x i32], [20 x i32]* %mult11, i32 0, i32 0
  store i32 1, i32* %mult12, align 1
  %mult13 = getelementptr inbounds [20 x i32], [20 x i32]* %mult11, i32 0, i32 1
  store i32 2, i32* %mult13, align 1
  %mult14 = getelementptr inbounds [20 x i32], [20 x i32]* %mult11, i32 0, i32 2
  store i32 3, i32* %mult14, align 1
  %mult15 = getelementptr inbounds [20 x i32], [20 x i32]* %mult11, i32 0, i32 3
  store i32 4, i32* %mult15, align 1
  %mult16 = getelementptr inbounds [20 x i32], [20 x i32]* %mult11, i32 0, i32 4
  store i32 5, i32* %mult16, align 1
  %mult17 = getelementptr inbounds [20 x i32], [20 x i32]* %mult11, i32 0, i32 5
  store i32 6, i32* %mult17, align 1
  %mult18 = getelementptr inbounds [20 x i32], [20 x i32]* %mult11, i32 0, i32 6
  store i32 7, i32* %mult18, align 1
  %mult19 = getelementptr inbounds [20 x i32], [20 x i32]* %mult11, i32 0, i32 7
  store i32 8, i32* %mult19, align 1
  %mult110 = getelementptr inbounds [20 x i32], [20 x i32]* %mult11, i32 0, i32 8
  store i32 9, i32* %mult110, align 1
  %mult111 = getelementptr inbounds [20 x i32], [20 x i32]* %mult11, i32 0, i32 9
  store i32 0, i32* %mult111, align 1
  %mult112 = getelementptr inbounds [20 x i32], [20 x i32]* %mult11, i32 0, i32 10
  store i32 1, i32* %mult112, align 1
  %mult113 = getelementptr inbounds [20 x i32], [20 x i32]* %mult11, i32 0, i32 11
  store i32 2, i32* %mult113, align 1
  %mult114 = getelementptr inbounds [20 x i32], [20 x i32]* %mult11, i32 0, i32 12
  store i32 3, i32* %mult114, align 1
  %mult115 = getelementptr inbounds [20 x i32], [20 x i32]* %mult11, i32 0, i32 13
  store i32 4, i32* %mult115, align 1
  %mult116 = getelementptr inbounds [20 x i32], [20 x i32]* %mult11, i32 0, i32 14
  store i32 5, i32* %mult116, align 1
  %mult117 = getelementptr inbounds [20 x i32], [20 x i32]* %mult11, i32 0, i32 15
  store i32 6, i32* %mult117, align 1
  %mult118 = getelementptr inbounds [20 x i32], [20 x i32]* %mult11, i32 0, i32 16
  store i32 7, i32* %mult118, align 1
  %mult119 = getelementptr inbounds [20 x i32], [20 x i32]* %mult11, i32 0, i32 17
  store i32 8, i32* %mult119, align 1
  %mult120 = getelementptr inbounds [20 x i32], [20 x i32]* %mult11, i32 0, i32 18
  store i32 9, i32* %mult120, align 1
  %mult121 = getelementptr inbounds [20 x i32], [20 x i32]* %mult11, i32 0, i32 19
  store i32 0, i32* %mult121, align 1
  %1 = bitcast [20 x i32]* %mult2 to i8*
  call void @llvm.memset.p0i8.i32(i8* align 4 %1, i8 0, i32 80, i1 false)
  %mult222 = getelementptr inbounds [20 x i32], [20 x i32]* %mult2, i32 0
  %mult223 = getelementptr inbounds [20 x i32], [20 x i32]* %mult222, i32 0, i32 0
  store i32 2, i32* %mult223, align 1
  %mult224 = getelementptr inbounds [20 x i32], [20 x i32]* %mult222, i32 0, i32 1
  store i32 3, i32* %mult224, align 1
  %mult225 = getelementptr inbounds [20 x i32], [20 x i32]* %mult222, i32 0, i32 2
  store i32 4, i32* %mult225, align 1
  %mult226 = getelementptr inbounds [20 x i32], [20 x i32]* %mult222, i32 0, i32 3
  store i32 2, i32* %mult226, align 1
  %mult227 = getelementptr inbounds [20 x i32], [20 x i32]* %mult222, i32 0, i32 4
  store i32 5, i32* %mult227, align 1
  %mult228 = getelementptr inbounds [20 x i32], [20 x i32]* %mult222, i32 0, i32 5
  store i32 7, i32* %mult228, align 1
  %mult229 = getelementptr inbounds [20 x i32], [20 x i32]* %mult222, i32 0, i32 6
  store i32 9, i32* %mult229, align 1
  %mult230 = getelementptr inbounds [20 x i32], [20 x i32]* %mult222, i32 0, i32 7
  store i32 9, i32* %mult230, align 1
  %mult231 = getelementptr inbounds [20 x i32], [20 x i32]* %mult222, i32 0, i32 8
  store i32 0, i32* %mult231, align 1
  %mult232 = getelementptr inbounds [20 x i32], [20 x i32]* %mult222, i32 0, i32 9
  store i32 1, i32* %mult232, align 1
  %mult233 = getelementptr inbounds [20 x i32], [20 x i32]* %mult222, i32 0, i32 10
  store i32 9, i32* %mult233, align 1
  %mult234 = getelementptr inbounds [20 x i32], [20 x i32]* %mult222, i32 0, i32 11
  store i32 8, i32* %mult234, align 1
  %mult235 = getelementptr inbounds [20 x i32], [20 x i32]* %mult222, i32 0, i32 12
  store i32 7, i32* %mult235, align 1
  %mult236 = getelementptr inbounds [20 x i32], [20 x i32]* %mult222, i32 0, i32 13
  store i32 6, i32* %mult236, align 1
  %mult237 = getelementptr inbounds [20 x i32], [20 x i32]* %mult222, i32 0, i32 14
  store i32 4, i32* %mult237, align 1
  %mult238 = getelementptr inbounds [20 x i32], [20 x i32]* %mult222, i32 0, i32 15
  store i32 3, i32* %mult238, align 1
  %mult239 = getelementptr inbounds [20 x i32], [20 x i32]* %mult222, i32 0, i32 16
  store i32 2, i32* %mult239, align 1
  %mult240 = getelementptr inbounds [20 x i32], [20 x i32]* %mult222, i32 0, i32 17
  store i32 1, i32* %mult240, align 1
  %mult241 = getelementptr inbounds [20 x i32], [20 x i32]* %mult222, i32 0, i32 18
  store i32 2, i32* %mult241, align 1
  %mult242 = getelementptr inbounds [20 x i32], [20 x i32]* %mult222, i32 0, i32 19
  store i32 2, i32* %mult242, align 1
  %lval2rval = load i32, i32* @len, align 1
  store i32 %lval2rval, i32* %len1, align 1
  %lval2rval43 = load i32, i32* @len, align 1
  store i32 %lval2rval43, i32* %len2, align 1
  %2 = bitcast [40 x i32]* %result to i8*
  call void @llvm.memset.p0i8.i32(i8* align 4 %2, i8 0, i32 160, i1 false)
  %result44 = getelementptr inbounds [40 x i32], [40 x i32]* %result, i32 0
  %result45 = getelementptr inbounds [40 x i32], [40 x i32]* %result44, i32 0, i32 0
  store i32 0, i32* %i, align 1
  br label %while.cond

return:                                           ; preds = %while.end144
  %constretval = load i32, i32* %retval, align 1
  ret i32 %constretval

while.cond:                                       ; preds = %while.body, %entry
  %lval2rval46 = load i32, i32* %i, align 1
  %lval2rval47 = load i32, i32* %len1, align 1
  %lesstmp = icmp slt i32 %lval2rval46, %lval2rval47
  %booltmp = icmp ne i1 %lesstmp, false
  br i1 %booltmp, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %lval2rval48 = load i32, i32* %i, align 1
  %mult149 = getelementptr inbounds [20 x i32], [20 x i32]* %mult1, i32 0, i32 %lval2rval48
  %lval2rval50 = load i32, i32* %mult149, align 1
  %lval2rval51 = load i32, i32* %i, align 1
  %c152 = getelementptr inbounds [65903345 x i32], [65903345 x i32]* %c1, i32 0, i32 %lval2rval51
  store i32 %lval2rval50, i32* %c152, align 1
  %lval2rval53 = load i32, i32* %i, align 1
  %addtmp = add i32 %lval2rval53, 1
  store i32 %addtmp, i32* %i, align 1
  br label %while.cond

while.end:                                        ; preds = %while.cond
  store i32 0, i32* %i, align 1
  br label %while.cond54

while.cond54:                                     ; preds = %while.body55, %while.end
  %lval2rval57 = load i32, i32* %i, align 1
  %lval2rval58 = load i32, i32* %len2, align 1
  %lesstmp59 = icmp slt i32 %lval2rval57, %lval2rval58
  %booltmp60 = icmp ne i1 %lesstmp59, false
  br i1 %booltmp60, label %while.body55, label %while.end56

while.body55:                                     ; preds = %while.cond54
  %lval2rval61 = load i32, i32* %i, align 1
  %mult262 = getelementptr inbounds [20 x i32], [20 x i32]* %mult2, i32 0, i32 %lval2rval61
  %lval2rval63 = load i32, i32* %mult262, align 1
  %lval2rval64 = load i32, i32* %i, align 1
  %c265 = getelementptr inbounds [65903345 x i32], [65903345 x i32]* %c2, i32 0, i32 %lval2rval64
  store i32 %lval2rval63, i32* %c265, align 1
  %lval2rval66 = load i32, i32* %i, align 1
  %addtmp67 = add i32 %lval2rval66, 1
  store i32 %addtmp67, i32* %i, align 1
  br label %while.cond54

while.end56:                                      ; preds = %while.cond54
  %lval2rval68 = load i32, i32* %len1, align 1
  %lval2rval69 = load i32, i32* %len2, align 1
  %addtmp70 = add i32 %lval2rval68, %lval2rval69
  %subtmp = sub i32 %addtmp70, 1
  store i32 %subtmp, i32* %n, align 1
  store i32 0, i32* %i, align 1
  br label %while.cond71

while.cond71:                                     ; preds = %while.body72, %while.end56
  %lval2rval74 = load i32, i32* %i, align 1
  %lval2rval75 = load i32, i32* %n, align 1
  %lessequaltmp = icmp sle i32 %lval2rval74, %lval2rval75
  %booltmp76 = icmp ne i1 %lessequaltmp, false
  br i1 %booltmp76, label %while.body72, label %while.end73

while.body72:                                     ; preds = %while.cond71
  %lval2rval77 = load i32, i32* %i, align 1
  %result78 = getelementptr inbounds [40 x i32], [40 x i32]* %result, i32 0, i32 %lval2rval77
  store i32 0, i32* %result78, align 1
  %lval2rval79 = load i32, i32* %i, align 1
  %addtmp80 = add i32 %lval2rval79, 1
  store i32 %addtmp80, i32* %i, align 1
  br label %while.cond71

while.end73:                                      ; preds = %while.cond71
  store i32 0, i32* %temp, align 1
  %lval2rval81 = load i32, i32* %len2, align 1
  %subtmp82 = sub i32 %lval2rval81, 1
  store i32 %subtmp82, i32* %i, align 1
  br label %while.cond83

while.cond83:                                     ; preds = %while.end95, %while.end73
  %lval2rval86 = load i32, i32* %i, align 1
  %greatertmp = icmp sgt i32 %lval2rval86, -1
  %booltmp87 = icmp ne i1 %greatertmp, false
  br i1 %booltmp87, label %while.body84, label %while.end85

while.body84:                                     ; preds = %while.cond83
  %lval2rval88 = load i32, i32* %i, align 1
  %c289 = getelementptr inbounds [65903345 x i32], [65903345 x i32]* %c2, i32 0, i32 %lval2rval88
  %lval2rval90 = load i32, i32* %c289, align 1
  store i32 %lval2rval90, i32* %t, align 1
  %lval2rval91 = load i32, i32* %len1, align 1
  %subtmp92 = sub i32 %lval2rval91, 1
  store i32 %subtmp92, i32* %j, align 1
  br label %while.cond93

while.end85:                                      ; preds = %while.cond83
  %result137 = getelementptr inbounds [40 x i32], [40 x i32]* %result, i32 0, i32 0
  %lval2rval138 = load i32, i32* %result137, align 1
  %equalexlaimtmp = icmp ne i32 %lval2rval138, 0
  %booltmp139 = icmp ne i1 %equalexlaimtmp, false
  br i1 %booltmp139, label %if.then135, label %if.end136

while.cond93:                                     ; preds = %if.end, %while.body84
  %lval2rval96 = load i32, i32* %j, align 1
  %greatertmp97 = icmp sgt i32 %lval2rval96, -1
  %booltmp98 = icmp ne i1 %greatertmp97, false
  br i1 %booltmp98, label %while.body94, label %while.end95

while.body94:                                     ; preds = %while.cond93
  %lval2rval99 = load i32, i32* %n, align 1
  %result100 = getelementptr inbounds [40 x i32], [40 x i32]* %result, i32 0, i32 %lval2rval99
  %lval2rval101 = load i32, i32* %result100, align 1
  %lval2rval102 = load i32, i32* %t, align 1
  %lval2rval103 = load i32, i32* %j, align 1
  %c1104 = getelementptr inbounds [65903345 x i32], [65903345 x i32]* %c1, i32 0, i32 %lval2rval103
  %lval2rval105 = load i32, i32* %c1104, align 1
  %multmp = mul i32 %lval2rval102, %lval2rval105
  %addtmp106 = add i32 %lval2rval101, %multmp
  store i32 %addtmp106, i32* %temp, align 1
  %lval2rval107 = load i32, i32* %temp, align 1
  %greaterequaltmp = icmp sge i32 %lval2rval107, 10
  %booltmp108 = icmp ne i1 %greaterequaltmp, false
  br i1 %booltmp108, label %if.then, label %if.else

while.end95:                                      ; preds = %while.cond93
  %lval2rval129 = load i32, i32* %n, align 1
  %lval2rval130 = load i32, i32* %len1, align 1
  %addtmp131 = add i32 %lval2rval129, %lval2rval130
  %subtmp132 = sub i32 %addtmp131, 1
  store i32 %subtmp132, i32* %n, align 1
  %lval2rval133 = load i32, i32* %i, align 1
  %subtmp134 = sub i32 %lval2rval133, 1
  store i32 %subtmp134, i32* %i, align 1
  br label %while.cond83

if.then:                                          ; preds = %while.body94
  %lval2rval109 = load i32, i32* %temp, align 1
  %lval2rval110 = load i32, i32* %n, align 1
  %result111 = getelementptr inbounds [40 x i32], [40 x i32]* %result, i32 0, i32 %lval2rval110
  store i32 %lval2rval109, i32* %result111, align 1
  %lval2rval112 = load i32, i32* %n, align 1
  %subtmp113 = sub i32 %lval2rval112, 1
  %result114 = getelementptr inbounds [40 x i32], [40 x i32]* %result, i32 0, i32 %subtmp113
  %lval2rval115 = load i32, i32* %result114, align 1
  %lval2rval116 = load i32, i32* %temp, align 1
  %multmp117 = sdiv i32 %lval2rval116, 10
  %addtmp118 = add i32 %lval2rval115, %multmp117
  %lval2rval119 = load i32, i32* %n, align 1
  %subtmp120 = sub i32 %lval2rval119, 1
  %result121 = getelementptr inbounds [40 x i32], [40 x i32]* %result, i32 0, i32 %subtmp120
  store i32 %addtmp118, i32* %result121, align 1
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then
  %lval2rval125 = load i32, i32* %j, align 1
  %subtmp126 = sub i32 %lval2rval125, 1
  store i32 %subtmp126, i32* %j, align 1
  %lval2rval127 = load i32, i32* %n, align 1
  %subtmp128 = sub i32 %lval2rval127, 1
  store i32 %subtmp128, i32* %n, align 1
  br label %while.cond93

if.else:                                          ; preds = %while.body94
  %lval2rval122 = load i32, i32* %temp, align 1
  %lval2rval123 = load i32, i32* %n, align 1
  %result124 = getelementptr inbounds [40 x i32], [40 x i32]* %result, i32 0, i32 %lval2rval123
  store i32 %lval2rval122, i32* %result124, align 1
  br label %if.end

if.then135:                                       ; preds = %while.end85
  %result140 = getelementptr inbounds [40 x i32], [40 x i32]* %result, i32 0, i32 0
  %lval2rval141 = load i32, i32* %result140, align 1
  call void @_sysy_putint(i32 %lval2rval141)
  br label %if.end136

if.end136:                                        ; preds = %if.then135, %while.end85
  store i32 1, i32* %i, align 1
  br label %while.cond142

while.cond142:                                    ; preds = %while.body143, %if.end136
  %lval2rval145 = load i32, i32* %i, align 1
  %lval2rval146 = load i32, i32* %len1, align 1
  %lval2rval147 = load i32, i32* %len2, align 1
  %addtmp148 = add i32 %lval2rval146, %lval2rval147
  %subtmp149 = sub i32 %addtmp148, 1
  %lessequaltmp150 = icmp sle i32 %lval2rval145, %subtmp149
  %booltmp151 = icmp ne i1 %lessequaltmp150, false
  br i1 %booltmp151, label %while.body143, label %while.end144

while.body143:                                    ; preds = %while.cond142
  %lval2rval152 = load i32, i32* %i, align 1
  %result153 = getelementptr inbounds [40 x i32], [40 x i32]* %result, i32 0, i32 %lval2rval152
  %lval2rval154 = load i32, i32* %result153, align 1
  call void @_sysy_putint(i32 %lval2rval154)
  %lval2rval155 = load i32, i32* %i, align 1
  %addtmp156 = add i32 %lval2rval155, 1
  store i32 %addtmp156, i32* %i, align 1
  br label %while.cond142

while.end144:                                     ; preds = %while.cond142
  store i32 0, i32* %retval, align 1
  br label %return
}

; Function Attrs: argmemonly nofree nosync nounwind willreturn writeonly
declare void @llvm.memset.p0i8.i32(i8* nocapture writeonly, i8, i32, i1 immarg) #0

attributes #0 = { argmemonly nofree nosync nounwind willreturn writeonly }
-------------------------------------------------------------------------------------------------------
