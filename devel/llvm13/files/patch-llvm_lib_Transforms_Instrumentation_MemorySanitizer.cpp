--- llvm/lib/Transforms/Instrumentation/MemorySanitizer.cpp.orig	2022-01-20 21:31:59 UTC
+++ llvm/lib/Transforms/Instrumentation/MemorySanitizer.cpp
@@ -416,6 +416,14 @@ static const MemoryMapParams Linux_AArch64_MemoryMapPa
   0x01000000000,   // OriginBase
 };
 
+// aarch64 FreeBSD
+static const MemoryMapParams FreeBSD_AArch64_MemoryMapParams = {
+  0x1800000000000, // AndMask
+  0x0400000000000, // XorMask
+  0x0200000000000, // ShadowBase
+  0x0700000000000, // OriginBase
+};
+
 // i386 FreeBSD
 static const MemoryMapParams FreeBSD_I386_MemoryMapParams = {
   0x000180000000,  // AndMask
@@ -465,6 +473,11 @@ static const PlatformMemoryMapParams Linux_ARM_MemoryM
   &Linux_AArch64_MemoryMapParams,
 };
 
+static const PlatformMemoryMapParams FreeBSD_ARM_MemoryMapParams = {
+  nullptr,
+  &FreeBSD_AArch64_MemoryMapParams,
+};
+
 static const PlatformMemoryMapParams FreeBSD_X86_MemoryMapParams = {
   &FreeBSD_I386_MemoryMapParams,
   &FreeBSD_X86_64_MemoryMapParams,
@@ -917,6 +930,9 @@ void MemorySanitizer::initializeModule(Module &M) {
     switch (TargetTriple.getOS()) {
       case Triple::FreeBSD:
         switch (TargetTriple.getArch()) {
+          case Triple::aarch64:
+            MapParams = FreeBSD_ARM_MemoryMapParams.bits64;
+            break;
           case Triple::x86_64:
             MapParams = FreeBSD_X86_MemoryMapParams.bits64;
             break;
@@ -4731,21 +4747,25 @@ struct VarArgAArch64Helper : public VarArgHelper {
       // we need to adjust the offset for both GR and VR fields based on
       // the __{gr,vr}_offs value (since they are stores based on incoming
       // named arguments).
+      Type *RegSaveAreaPtrTy = IRB.getInt8PtrTy();
 
       // Read the stack pointer from the va_list.
-      Value *StackSaveAreaPtr = getVAField64(IRB, VAListTag, 0);
+      Value *StackSaveAreaPtr =
+          IRB.CreateIntToPtr(getVAField64(IRB, VAListTag, 0), RegSaveAreaPtrTy);
 
       // Read both the __gr_top and __gr_off and add them up.
       Value *GrTopSaveAreaPtr = getVAField64(IRB, VAListTag, 8);
       Value *GrOffSaveArea = getVAField32(IRB, VAListTag, 24);
 
-      Value *GrRegSaveAreaPtr = IRB.CreateAdd(GrTopSaveAreaPtr, GrOffSaveArea);
+      Value *GrRegSaveAreaPtr = IRB.CreateIntToPtr(
+          IRB.CreateAdd(GrTopSaveAreaPtr, GrOffSaveArea), RegSaveAreaPtrTy);
 
       // Read both the __vr_top and __vr_off and add them up.
       Value *VrTopSaveAreaPtr = getVAField64(IRB, VAListTag, 16);
       Value *VrOffSaveArea = getVAField32(IRB, VAListTag, 28);
 
-      Value *VrRegSaveAreaPtr = IRB.CreateAdd(VrTopSaveAreaPtr, VrOffSaveArea);
+      Value *VrRegSaveAreaPtr = IRB.CreateIntToPtr(
+          IRB.CreateAdd(VrTopSaveAreaPtr, VrOffSaveArea), RegSaveAreaPtrTy);
 
       // It does not know how many named arguments is being used and, on the
       // callsite all the arguments were saved.  Since __gr_off is defined as
