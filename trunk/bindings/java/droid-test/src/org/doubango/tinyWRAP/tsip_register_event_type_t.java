/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.doubango.tinyWRAP;

public final class tsip_register_event_type_t {
  public final static tsip_register_event_type_t tsip_i_register = new tsip_register_event_type_t("tsip_i_register");
  public final static tsip_register_event_type_t tsip_ai_register = new tsip_register_event_type_t("tsip_ai_register");
  public final static tsip_register_event_type_t tsip_o_register = new tsip_register_event_type_t("tsip_o_register");
  public final static tsip_register_event_type_t tsip_ao_register = new tsip_register_event_type_t("tsip_ao_register");
  public final static tsip_register_event_type_t tsip_i_unregister = new tsip_register_event_type_t("tsip_i_unregister");
  public final static tsip_register_event_type_t tsip_ai_unregister = new tsip_register_event_type_t("tsip_ai_unregister");
  public final static tsip_register_event_type_t tsip_o_unregister = new tsip_register_event_type_t("tsip_o_unregister");
  public final static tsip_register_event_type_t tsip_ao_unregister = new tsip_register_event_type_t("tsip_ao_unregister");

  public final int swigValue() {
    return swigValue;
  }

  public String toString() {
    return swigName;
  }

  public static tsip_register_event_type_t swigToEnum(int swigValue) {
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (int i = 0; i < swigValues.length; i++)
      if (swigValues[i].swigValue == swigValue)
        return swigValues[i];
    throw new IllegalArgumentException("No enum " + tsip_register_event_type_t.class + " with value " + swigValue);
  }

  private tsip_register_event_type_t(String swigName) {
    this.swigName = swigName;
    this.swigValue = swigNext++;
  }

  private tsip_register_event_type_t(String swigName, int swigValue) {
    this.swigName = swigName;
    this.swigValue = swigValue;
    swigNext = swigValue+1;
  }

  private tsip_register_event_type_t(String swigName, tsip_register_event_type_t swigEnum) {
    this.swigName = swigName;
    this.swigValue = swigEnum.swigValue;
    swigNext = this.swigValue+1;
  }

  private static tsip_register_event_type_t[] swigValues = { tsip_i_register, tsip_ai_register, tsip_o_register, tsip_ao_register, tsip_i_unregister, tsip_ai_unregister, tsip_o_unregister, tsip_ao_unregister };
  private static int swigNext = 0;
  private final int swigValue;
  private final String swigName;
}

