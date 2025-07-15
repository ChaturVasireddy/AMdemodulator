################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
device/%.obj: ../device/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"/Applications/ti/ccs2020/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="/Users/chaturvasireddy/Documents/VScode/AMdemodulator/mcu_rt_testing/ti_am_demodulator" --include_path="/Users/chaturvasireddy/Documents/VScode/AMdemodulator/mcu_rt_testing/ti_am_demodulator/device" --include_path="/Users/chaturvasireddy/ti/C2000Ware_5_05_00_00/driverlib/f2837xd/driverlib/" --include_path="/Applications/ti/ccs2020/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="device/$(basename $(<F)).d_raw" --include_path="/Users/chaturvasireddy/Documents/VScode/AMdemodulator/mcu_rt_testing/ti_am_demodulator/CPU1_RAM/syscfg" --obj_directory="device" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

device/%.obj: ../device/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"/Applications/ti/ccs2020/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu2 -Ooff --include_path="/Users/chaturvasireddy/Documents/VScode/AMdemodulator/mcu_rt_testing/ti_am_demodulator" --include_path="/Users/chaturvasireddy/Documents/VScode/AMdemodulator/mcu_rt_testing/ti_am_demodulator/device" --include_path="/Users/chaturvasireddy/ti/C2000Ware_5_05_00_00/driverlib/f2837xd/driverlib/" --include_path="/Applications/ti/ccs2020/ccs/tools/compiler/ti-cgt-c2000_22.6.2.LTS/include" --define=DEBUG --define=CPU1 --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="device/$(basename $(<F)).d_raw" --include_path="/Users/chaturvasireddy/Documents/VScode/AMdemodulator/mcu_rt_testing/ti_am_demodulator/CPU1_RAM/syscfg" --obj_directory="device" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


