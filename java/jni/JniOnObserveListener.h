/*
* //******************************************************************
* //
* // Copyright 2015 Intel Corporation.
* //
* //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
* //
* // Licensed under the Apache License, Version 2.0 (the "License");
* // you may not use this file except in compliance with the License.
* // You may obtain a copy of the License at
* //
* //      http://www.apache.org/licenses/LICENSE-2.0
* //
* // Unless required by applicable law or agreed to in writing, software
* // distributed under the License is distributed on an "AS IS" BASIS,
* // WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* // See the License for the specific language governing permissions and
* // limitations under the License.
* //
* //-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
*/
#include "JniOcStack.h"

#ifndef _Included_org_iotivity_base_OcResource_OnObserveListener
#define _Included_org_iotivity_base_OcResource_OnObserveListener

class JniOcResource;
#ifdef WITH_CLOUD
class JniOcAccountManager;
#endif

class JniOnObserveListener
{
public:
    JniOnObserveListener(JNIEnv *env, jobject jListener, JniOcResource* owner);
#ifdef WITH_CLOUD
    JniOnObserveListener(JNIEnv *env, jobject jListener, JniOcAccountManager* owner);
#endif
    ~JniOnObserveListener();
    void onObserveCallback(const OC::HeaderOptions headerOptions, const OC::OCRepresentation& rep,
        const int& eCode, const int& sequenceNumber);
    jweak getJWListener();
private:
    jweak m_jwListener;
    JniOcResource* m_ownerResource;
#ifdef WITH_CLOUD
    JniOcAccountManager* m_ownerAccountManager;
#endif
    void checkExAndRemoveListener(JNIEnv *env);
};

#endif
