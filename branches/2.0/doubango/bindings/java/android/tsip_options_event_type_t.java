/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.8
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.doubango.tinyWRAP;

public enum tsip_options_event_type_t {
  tsip_i_options,
  tsip_ao_options;

  public final int swigValue() {
    return swigValue;
  }

  public static tsip_options_event_type_t swigToEnum(int swigValue) {
    tsip_options_event_type_t[] swigValues = tsip_options_event_type_t.class.getEnumConstants();
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (tsip_options_event_type_t swigEnum : swigValues)
      if (swigEnum.swigValue == swigValue)
        return swigEnum;
    throw new IllegalArgumentException("No enum " + tsip_options_event_type_t.class + " with value " + swigValue);
  }

  @SuppressWarnings("unused")
  private tsip_options_event_type_t() {
    this.swigValue = SwigNext.next++;
  }

  @SuppressWarnings("unused")
  private tsip_options_event_type_t(int swigValue) {
    this.swigValue = swigValue;
    SwigNext.next = swigValue+1;
  }

  @SuppressWarnings("unused")
  private tsip_options_event_type_t(tsip_options_event_type_t swigEnum) {
    this.swigValue = swigEnum.swigValue;
    SwigNext.next = this.swigValue+1;
  }

  private final int swigValue;

  private static class SwigNext {
    private static int next = 0;
  }
}

