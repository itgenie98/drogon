//
// Copyright 2018, An Tao.  All rights reserved.
//
// Use of this source code is governed by a MIT license
// that can be found in the License file.

#include <drogon/HttpViewBase.h>
#include <drogon/DrClassMap.h>
#include <trantor/utils/Logger.h>
#include <memory>
using namespace drogon;
HttpResponse* HttpViewBase::genHttpResponse(std::string viewName,const HttpViewData &data)
{
    LOG_TRACE<<"http view name="<<viewName;
    auto obj=std::shared_ptr<DrObjectBase>(drogon::DrClassMap::newObject(viewName));
    if(obj)
    {
        auto view= std::dynamic_pointer_cast<HttpViewBase>(obj);
        if(view)
        {
            return view->genHttpResponse(data);
        }
    }
    return drogon::HttpResponse::notFoundResponse();
}