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
