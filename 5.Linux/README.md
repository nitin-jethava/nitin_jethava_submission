### **1) Create a new folder `test_new` in the home directory.**

```bash
mkdir ~/test_new
```
- `~` means your **home** directory.
- `mkdir` is used to **make a directory**.

---

### **2) Remove all permissions of the `test_new` directory.**

```bash
chmod 000 ~/test_new
```
- `chmod 000` removes **read (r)**, **write (w)**, and **execute (x)** permissions for **owner, group, and others**.

---

### **3) Create a `new.txt` file in the `test_new` directory.**
(⚡ *without changing permissions* — **impossible directly**, because no permission to enter/write inside the directory.)

👉 So **direct creation** without changing permission is **NOT possible**.  
You must **have at least write and execute** permissions on a directory to create a file inside it.

> **Meaning:**  
> - You can't create a file without fixing permissions temporarily.

**Alternate Approach to Explain:**
- You must **first** give permissions (temporarily), create the file, and then **again remove** permissions.

Example:
```bash
chmod 700 ~/test_new  # Give owner permission temporarily
touch ~/test_new/new.txt
chmod 000 ~/test_new  # Remove permissions again
```
Otherwise, you will get **Permission denied** errors.

---

### **4) Delete the `test_new` directory.**
(⚡ *without changing permissions* — again **impossible** directly.)

> Because **no execute (`x`) permission** on the directory means **you cannot access, delete, or even list it**.

🔵 **You must restore permission** first to delete it:

```bash
chmod 700 ~/test_new  # Temporarily allow permission
rm -r ~/test_new
```

---

### 🔥 **Summary in short:**

| Step | Command | Note |
|:----|:--------|:-----|
| Create folder | `mkdir ~/test_new` | OK |
| Remove all permissions | `chmod 000 ~/test_new` | OK |
| Create file inside | **Not possible without permission** | Must give temporary permission |
| Delete folder | **Not possible without permission** | Must give temporary permission |
