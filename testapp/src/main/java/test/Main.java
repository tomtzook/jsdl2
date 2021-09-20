package test;

import sdl2.JoystickJni;
import sdl2.SdlJni;

public class Main {

    public static void main(String[] args) {
        System.load("/home/tomtzook/projects/tryouts/flashlib-plugins/build/sdl/cmake/libsdl_jni.so");

        int result = SdlJni.init0(0x00002000 | 0x00000200);
        if (result != 0) {
            System.err.printf("init error (%d)\n", result);
            String error = SdlJni.getError();
            System.err.printf("\t%s\n", error);
            return;
        }

        try {
            long ptr = JoystickJni.open(0);
            if (ptr == 0) {
                System.err.printf("open error (%d)\n", result);
                String error = SdlJni.getError();
                System.err.printf("\t%s\n", error);
                return;
            }

            int axes = JoystickJni.getNumAxes(ptr);
            int buttons = JoystickJni.getNumButtons(ptr);

            System.out.printf("JOY 0x%x: axes: %d, buttons: %d\n",
                    ptr, axes, buttons);
        } finally {
            SdlJni.quit();
        }
    }
}
