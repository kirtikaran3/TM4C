################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
lab2_clock_startup_msp432p401r_ccs.obj: ../lab2_clock_startup_msp432p401r_ccs.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/media/kirti/Tools/CCS7IDE/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/media/kirti/Tools/CCS7IDE/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --include_path="/media/kirti/Windows/Users/Kirti/Documents/ARM_TM4C/lab2_clock/driverlib" --include_path="/media/kirti/Tools/CCS7IDE/ccsv7/ccs_base/arm/include" --include_path="/media/kirti/Tools/CCS7IDE/ccsv7/ccs_base/arm/include/CMSIS" -g --gcc --define=TARGET_IS_MSP432P4XX --define=ccs --define=__MSP432P401R__ --diag_wrap=off --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="lab2_clock_startup_msp432p401r_ccs.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

lab2_clock_system.obj: ../lab2_clock_system.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/media/kirti/Tools/CCS7IDE/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/media/kirti/Tools/CCS7IDE/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --include_path="/media/kirti/Windows/Users/Kirti/Documents/ARM_TM4C/lab2_clock/driverlib" --include_path="/media/kirti/Tools/CCS7IDE/ccsv7/ccs_base/arm/include" --include_path="/media/kirti/Tools/CCS7IDE/ccsv7/ccs_base/arm/include/CMSIS" -g --gcc --define=TARGET_IS_MSP432P4XX --define=ccs --define=__MSP432P401R__ --diag_wrap=off --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="lab2_clock_system.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

system_msp432p401r.obj: ../system_msp432p401r.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP432 Compiler'
	"/media/kirti/Tools/CCS7IDE/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="/media/kirti/Tools/CCS7IDE/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --include_path="/media/kirti/Windows/Users/Kirti/Documents/ARM_TM4C/lab2_clock/driverlib" --include_path="/media/kirti/Tools/CCS7IDE/ccsv7/ccs_base/arm/include" --include_path="/media/kirti/Tools/CCS7IDE/ccsv7/ccs_base/arm/include/CMSIS" -g --gcc --define=TARGET_IS_MSP432P4XX --define=ccs --define=__MSP432P401R__ --diag_wrap=off --diag_warning=225 --display_error_number --preproc_with_compile --preproc_dependency="system_msp432p401r.d" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


