################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
interrupts.obj: ../interrupts.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/media/kirti/Tools/CCS7IDE/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/media/kirti/Tools/CCS7IDE/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --include_path="C:/TEXASINSTRUMENTS/TivaWare_C_Series-2.1.3.156" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="interrupts.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

tm4c123gh6pm_startup_ccs.obj: ../tm4c123gh6pm_startup_ccs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/media/kirti/Tools/CCS7IDE/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/media/kirti/Tools/CCS7IDE/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --include_path="C:/TEXASINSTRUMENTS/TivaWare_C_Series-2.1.3.156" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --diag_wrap=off --diag_warning=225 --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="tm4c123gh6pm_startup_ccs.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


