-- -------------------------------------------------------------
-- 
-- File Name: hdl_prj\hdlsrc\pulse_detector_v4_4\Compute_Power.vhd
-- Created: 2022-07-05 22:17:10
-- 
-- Generated by MATLAB 9.3 and HDL Coder 3.11
-- 
-- -------------------------------------------------------------


-- -------------------------------------------------------------
-- 
-- Module: Compute_Power
-- Source Path: pulse_detector_v4_4/Pulse Detector/Compute Power
-- Hierarchy Level: 1
-- 
-- -------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;

ENTITY Compute_Power IS
  PORT( data_in_re                        :   IN    std_logic_vector(39 DOWNTO 0);  -- sfix40_En37
        data_in_im                        :   IN    std_logic_vector(39 DOWNTO 0);  -- sfix40_En37
        data_out                          :   OUT   std_logic_vector(17 DOWNTO 0)  -- sfix18_En11
        );
END Compute_Power;


ARCHITECTURE rtl OF Compute_Power IS

  -- Signals
  SIGNAL data_in_re_signed                : signed(39 DOWNTO 0);  -- sfix40_En37
  SIGNAL data_in_im_signed                : signed(39 DOWNTO 0);  -- sfix40_En37
  SIGNAL Data_Type_Conversion_out1_re     : signed(17 DOWNTO 0);  -- sfix18_En15
  SIGNAL Data_Type_Conversion_out1_im     : signed(17 DOWNTO 0);  -- sfix18_En15
  SIGNAL Product1_out1                    : signed(35 DOWNTO 0);  -- sfix36_En30
  SIGNAL Product_out1                     : signed(35 DOWNTO 0);  -- sfix36_En30
  SIGNAL Add_add_cast                     : signed(36 DOWNTO 0);  -- sfix37_En30
  SIGNAL Add_add_cast_1                   : signed(36 DOWNTO 0);  -- sfix37_En30
  SIGNAL Add_out1                         : signed(36 DOWNTO 0);  -- sfix37_En30
  SIGNAL Data_Type_Conversion1_out1       : signed(17 DOWNTO 0);  -- sfix18_En11

BEGIN
  data_in_re_signed <= signed(data_in_re);

  data_in_im_signed <= signed(data_in_im);

  Data_Type_Conversion_out1_re <= data_in_re_signed(39 DOWNTO 22);
  Data_Type_Conversion_out1_im <= data_in_im_signed(39 DOWNTO 22);

  Product1_out1 <= Data_Type_Conversion_out1_re * Data_Type_Conversion_out1_re;

  Product_out1 <= Data_Type_Conversion_out1_im * Data_Type_Conversion_out1_im;

  Add_add_cast <= resize(Product1_out1, 37);
  Add_add_cast_1 <= resize(Product_out1, 37);
  Add_out1 <= Add_add_cast + Add_add_cast_1;

  Data_Type_Conversion1_out1 <= Add_out1(36 DOWNTO 19);

  data_out <= std_logic_vector(Data_Type_Conversion1_out1);

END rtl;

