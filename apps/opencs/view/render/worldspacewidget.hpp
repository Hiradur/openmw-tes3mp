#ifndef OPENCS_VIEW_WORLDSPACEWIDGET_H
#define OPENCS_VIEW_WORLDSPACEWIDGET_H

#include "scenewidget.hpp"

#include "navigation1st.hpp"
#include "navigationfree.hpp"
#include "navigationorbit.hpp"
#include <apps/opencs/model/doc/document.hpp>
#include <apps/opencs/model/world/tablemimedata.hpp>

namespace CSMWorld
{
    class UniversalId;
}

namespace CSVWidget
{
    class SceneToolMode;
    class SceneToolToggle;
    class SceneToolbar;
    class SceneToolRun;
}

namespace CSVWorld
{
    class PhysicsSystem;
}

class QElapsedTimer;

namespace CSVRender
{
    class WorldspaceWidget : public SceneWidget
    {
            Q_OBJECT

            CSVRender::Navigation1st m1st;
            CSVRender::NavigationFree mFree;
            CSVRender::NavigationOrbit mOrbit;
            CSVWidget::SceneToolToggle *mSceneElements;
            CSVWidget::SceneToolRun *mRun;
            CSMDoc::Document& mDocument;
            CSVWorld::PhysicsSystem *mPhysics;

            enum MouseState
            {
                Mouse_Grab,
                Mouse_Drag,
                Mouse_Edit,
                Mouse_Default
            };
            MouseState mMouseState;

            QPoint mOldPos;
            std::string mCurrentObj;
            std::string mGrabbedSceneNode;
            QElapsedTimer *mMouseEventTimer;
            Ogre::Plane *mPlane;
            Ogre::Vector3 mOrigObjPos;
            Ogre::Vector3 mOrigMousePos;
            Ogre::Vector3 mCurrentMousePos;
            float mZOffset;
            std::map<std::string, std::vector<std::string> > mSelectedEntities;

        public:

            enum DropType
            {
                Type_CellsInterior,
                Type_CellsExterior,
                Type_Other,
                Type_DebugProfile
            };

            enum dropRequirments
            {
                canHandle,
                needPaged,
                needUnpaged,
                ignored //either mixed cells, or not cells
            };

            WorldspaceWidget (CSMDoc::Document& document, QWidget *parent = 0);
            ~WorldspaceWidget ();

            CSVWidget::SceneToolMode *makeNavigationSelector (CSVWidget::SceneToolbar *parent);
            ///< \attention The created tool is not added to the toolbar (via addTool). Doing that
            /// is the responsibility of the calling function.

            /// \attention The created tool is not added to the toolbar (via addTool). Doing
            /// that is the responsibility of the calling function.
            CSVWidget::SceneToolToggle *makeSceneVisibilitySelector (
                CSVWidget::SceneToolbar *parent);

            /// \attention The created tool is not added to the toolbar (via addTool). Doing
            /// that is the responsibility of the calling function.
            CSVWidget::SceneToolRun *makeRunTool (CSVWidget::SceneToolbar *parent);

            void selectDefaultNavigationMode();

            static DropType getDropType(const std::vector<CSMWorld::UniversalId>& data);

            virtual dropRequirments getDropRequirements(DropType type) const;

            virtual void useViewHint (const std::string& hint);
            ///< Default-implementation: ignored.

            /// \return Drop handled?
            virtual bool handleDrop (const std::vector<CSMWorld::UniversalId>& data,
                DropType type);

            virtual unsigned int getElementMask() const;

        protected:

            virtual void addVisibilitySelectorButtons (CSVWidget::SceneToolToggle *tool);

            CSMDoc::Document& getDocument();

            virtual void updateOverlay();

            CSVWorld::PhysicsSystem *getPhysics();

            virtual void mouseMoveEvent (QMouseEvent *event);
            virtual void mousePressEvent (QMouseEvent *event);
            virtual void mouseReleaseEvent (QMouseEvent *event);
            virtual void mouseDoubleClickEvent (QMouseEvent *event);
            virtual void wheelEvent (QWheelEvent *event);

        private:

            void dragEnterEvent(QDragEnterEvent *event);

            void dropEvent(QDropEvent* event);

            void dragMoveEvent(QDragMoveEvent *event);

            virtual std::string getStartupInstruction() = 0;

            void placeObject(const std::string sceneNode, const Ogre::Vector3 &pos);
            std::pair<std::string, Ogre::Vector3> terrainUnderCursor(const int mouseX, const int mouseY);
            std::pair<std::string, Ogre::Vector3> objectUnderCursor(const int mouseX, const int mouseY);
            std::pair<bool, Ogre::Vector3> mousePositionOnPlane(const QPoint &pos, const Ogre::Plane &plane);
            void updateSelectionHighlight(const std::string sceneNode, const Ogre::Vector3 &position);

            void updateSceneWidgets();
            bool isDebug();

        private slots:

            void selectNavigationMode (const std::string& mode);

            virtual void referenceableDataChanged (const QModelIndex& topLeft,
                const QModelIndex& bottomRight) = 0;

            virtual void referenceableAboutToBeRemoved (const QModelIndex& parent, int start, int end) = 0;

            virtual void referenceableAdded (const QModelIndex& index, int start, int end) = 0;

            virtual void referenceDataChanged (const QModelIndex& topLeft, const QModelIndex& bottomRight) = 0;

            virtual void referenceAboutToBeRemoved (const QModelIndex& parent, int start, int end) = 0;

            virtual void referenceAdded (const QModelIndex& index, int start, int end) = 0;

            virtual void runRequest (const std::string& profile);

            void debugProfileDataChanged (const QModelIndex& topLeft,
                const QModelIndex& bottomRight);

            void debugProfileAboutToBeRemoved (const QModelIndex& parent, int start, int end);


        protected slots:

            void elementSelectionChanged();

        signals:

            void closeRequest();

            void dataDropped(const std::vector<CSMWorld::UniversalId>& data);
    };
}

#endif
