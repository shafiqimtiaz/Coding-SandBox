import org.junit.*;

import static org.junit.Assert.assertEquals;

public class testMessageUtil {
    String message = "Robert";
    MessageUtil messageUtil = new MessageUtil(message);

    @BeforeClass
    public static void beforeClass() {
        System.out.println("in before TestJunit1 class");
    }

    @AfterClass
    public static void afterClass() {
        System.out.println("in after TestJunit1 class");
    }

    @Before
    public void before() {
        System.out.println("in before TestJunit1 test case");
    }

    @After
    public void after() {
        System.out.println("in after TestJunit1 test case");
    }

    @Test
    public void testPrintMessage() {
        System.out.println("Inside testPrintMessage()");
        assertEquals(message, messageUtil.printMessage());
    }

    @Test
    public void testSalutationMessage() {
        System.out.println("Inside testSalutationMessage()");
        message = "Hi!" + "Robert";
        assertEquals(message, messageUtil.salutationMessage());
    }
}
