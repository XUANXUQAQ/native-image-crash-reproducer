import java.nio.file.Path;
import java.util.function.Supplier;

public enum NativeTest {
    INSTANCE;

    static {
        String dllPath = Path.of("Test.dll").toAbsolutePath().toString();
        System.load(dllPath);
    }

    public native void nativeFunc(Supplier<String> testSupplier);
}
