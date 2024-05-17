--- src/util/find_uid.c.orig	2024-01-12 12:05:40 UTC
+++ src/util/find_uid.c
@@ -71,7 +71,7 @@ static errno_t get_uid_from_pid(const pid_t pid, uid_t
     uint32_t num=0;
     errno_t error;
 
-    ret = snprintf(path, PATHLEN, "/proc/%d/status", pid);
+    ret = snprintf(path, PATHLEN, "/compat/linux/proc/%d/status", pid);
     if (ret < 0) {
         DEBUG(SSSDBG_CRIT_FAILURE, "snprintf failed\n");
         return EINVAL;
@@ -212,7 +212,7 @@ static errno_t name_to_pid(const char *name, pid_t *pi
         return EINVAL;
     }
 
-    if (num <= 0 || num >= INT_MAX) {
+    if (num < 0 || num >= INT_MAX) {
         DEBUG(SSSDBG_CRIT_FAILURE, "pid out of range.\n");
         return ERANGE;
     }
@@ -240,7 +240,7 @@ static errno_t get_active_uid_linux(hash_table_t *tabl
     hash_key_t key;
     hash_value_t value;
 
-    proc_dir = opendir("/proc");
+    proc_dir = opendir("/compat/linux/proc");
     if (proc_dir == NULL) {
         ret = errno;
         DEBUG(SSSDBG_CRIT_FAILURE, "Cannot open proc dir.\n");
@@ -327,9 +327,9 @@ errno_t get_uid_table(TALLOC_CTX *mem_ctx, hash_table_
 
 errno_t get_uid_table(TALLOC_CTX *mem_ctx, hash_table_t **table)
 {
-#ifdef __linux__
     int ret;
 
+#if 1
     ret = hash_create_ex(0, table, 0, 0, 0, 0,
                          hash_talloc, hash_talloc_free, mem_ctx,
                          NULL, NULL);
